// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine
#include "CoreMinimal.h"
#include "InventoryDataStructs.generated.h"

USTRUCT(BlueprintType)
struct FLines {

	GENERATED_BODY()

	FLines() {

	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> XLines;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> YLines;
};

class GRIDINVENTORYCPP_API InventoryDataStructs
{


};
