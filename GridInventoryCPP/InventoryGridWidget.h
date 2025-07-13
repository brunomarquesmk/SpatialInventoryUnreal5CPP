// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Imported
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "InventoryDataStructs.h"

// Engine
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryGridWidget.generated.h"

class UCanvasPanel;
class UBorder;


UCLASS()
class GRIDINVENTORYCPP_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UBorder* GridBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* GridCanvasPanel;

	int32 Columns;

	int32 Rows;

	float TileSize;

	TArray<float> StartX;
	TArray<float> StartY;
	TArray<float> EndX;
	TArray<float> EndY;

	FLines* LineStructData;

	// Functions

	virtual void NativeConstruct() override;
	void CreateLineSegments();
	virtual int32 NativePaint(const FPaintArgs& Args,
		const FGeometry& AllocatedGeometry,
		const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements,
		int32 LayerId,
		const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled) const override;

};
