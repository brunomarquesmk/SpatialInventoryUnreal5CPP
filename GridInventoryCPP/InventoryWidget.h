// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UCanvasPanel;
class UBorder;
class UBackgroundBlur;


UCLASS()
class GRIDINVENTORYCPP_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleANywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleANywhere, meta = (BindWidget), Category = "UI")
	UBorder* BackgroundBorder;
	
	UPROPERTY(VisibleANywhere, meta = (BindWidget), Category = "UI")
	UBackgroundBlur* Blur;

protected:
	
	virtual void NativeConstruct() override;

};
