// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"
#include "GridInventoryCPPCharacter.h"
#include "InventoryComponent.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AGridInventoryCPPCharacter* CharacterReference;
	CharacterReference = Cast<AGridInventoryCPPCharacter>(GetOwningPlayerPawn());

	UInventoryComponent* InventoryComponent;
	InventoryComponent = CharacterReference->InventoryComponent;

	if (!CharacterReference)
		return;

	Columns = InventoryComponent->Columns;
	Rows = InventoryComponent->Rows;
	TileSize = InventoryComponent->TileSize;

	FVector2D LocalTileSize(InventoryComponent->TileSize, InventoryComponent->TileSize);
	float NewWidth = Columns * LocalTileSize.X;
	float NewHeight = Rows * LocalTileSize.Y;

	LineStructData = new FLines();
	StartX = {};
	StartY = {};
	EndX = {};
	EndY = {};
	
	UCanvasPanelSlot* BorderAsCanvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(GridBorder);
	BorderAsCanvasSlot->SetSize(FVector2D(NewWidth, NewHeight));

	CreateLineSegments();
}

void UInventoryGridWidget::CreateLineSegments()
{
	StartX.Empty();
	StartY.Empty();
	EndX.Empty();
	EndY.Empty();
	
	for (int32 i = 0; i <= Columns; i++)
	{
		float X{ i * TileSize };

		LineStructData->XLines.Add(FVector2D(X, X));
		LineStructData->YLines.Add(FVector2D(0.0f, Rows * TileSize));
	}

	for (int32 i = 0; i <= Rows; i++)
	{
		float Y{ i * TileSize };

		LineStructData->YLines.Add(FVector2D(Y, Y));
		LineStructData->XLines.Add(FVector2D(0.0f, Columns * TileSize));
	}

	for (int32 i = 0; i < LineStructData->XLines.Num(); i++)
	{
		StartX.Add(LineStructData->XLines[i].X);
		EndX.Add(LineStructData->XLines[i].Y);
		StartY.Add(LineStructData->YLines[i].X);
		EndY.Add(LineStructData->YLines[i].Y);
	}
}

int32 UInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// Call the base class implementation
	int32 Result = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FPaintContext PaintContext(AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FLinearColor CustomColor(0.5f, 0.5f, 0.5f, 0.5f);

	FVector2D TopLeftCorner = GridBorder->GetCachedGeometry().GetLocalPositionAtCoordinates(FVector2D(0.0f, 0.0f));


	int32 Half = LineStructData->XLines.Num() / 2;

	for (int32 i = 0; i < Half; i++)
	{
		FVector2D Start = FVector2D(StartX[i], StartY[i]) + TopLeftCorner;
		FVector2D End = FVector2D(EndX[i], EndY[i]) + TopLeftCorner;
		UWidgetBlueprintLibrary::DrawLine(PaintContext, Start, End, CustomColor);
	}

	for (int32 i = Half; i < LineStructData->XLines.Num(); i++)
	{
		FVector2D Start = FVector2D(StartX[i], StartY[i]) + TopLeftCorner;
		FVector2D End = FVector2D(EndX[i], EndY[i]) + TopLeftCorner;
		UWidgetBlueprintLibrary::DrawLine(PaintContext, Start, End, CustomColor);
	}

	return Result;
}
