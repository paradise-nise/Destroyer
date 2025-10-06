// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Item.generated.h"

class USphereComponent;
UCLASS()
class DESTROYER_API AA_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AA_Item();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sine Parameter")
	float Amplitude = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameter")
	float TimeConstant = 5.f;
	UFUNCTION(BlueprintPure)
	float TransformedSin();
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T A, T B);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	float RunningTime;
};

template<typename T>
inline T AA_Item::Avg(T A, T B)
{
	return (A + B) / 2;
}
