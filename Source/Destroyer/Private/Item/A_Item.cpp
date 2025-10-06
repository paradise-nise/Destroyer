// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/A_Item.h"
#include "Destroyer/DebugMacros.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AA_Item::AA_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AA_Item::BeginPlay()
{
	Super::BeginPlay();

}

float AA_Item::TransformedSin()
{
	return FMath::Sin(RunningTime * TimeConstant) * Amplitude;
}
float AA_Item::TransformedCos()
{
	return FMath::Cos(RunningTime * TimeConstant) * Amplitude;
}

// Called every frame
void AA_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

}

