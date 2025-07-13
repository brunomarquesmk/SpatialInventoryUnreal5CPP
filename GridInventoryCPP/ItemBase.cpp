// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/SphereComponent.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	Mesh->SetupAttachment(RootComponent);
	Sphere->SetupAttachment(Mesh);

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

