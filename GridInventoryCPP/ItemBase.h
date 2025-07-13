// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"


class USphereComponent;
UCLASS()
class GRIDINVENTORYCPP_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();

	virtual void Tick(float DeltaTime) override;

	 UPROPERTY(EditAnywhere)
	 UStaticMeshComponent* Mesh;
	 
	 UPROPERTY(EditAnywhere)
	 USphereComponent* Sphere;
	
protected:
	virtual void BeginPlay() override;


};
