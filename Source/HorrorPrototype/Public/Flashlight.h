// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SpotLightComponent.h"
#include "Flashlight.generated.h"

UCLASS()
class HORRORPROTOTYPE_API AFlashlight : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RootComponent"))
	USceneComponent* M_RootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "FlashlightMesh"))
	UStaticMeshComponent* M_FlashlightMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "Spotlight"))
	USpotLightComponent* M_Spotlight;
	
public:	
	// Sets default values for this actor's properties
	AFlashlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "FlashlightOn?"))
	bool M_bFlashlightOn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "CurrentBattery"))
	float M_CurrentBattery;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "MaxBattery"))
	float M_MaxBattery = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "DecayRate"))
	float M_DecayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "ChargeRate"))
	float M_ChargeRate;

	bool M_bPunishement;

	float M_Delay = 10;

	UPROPERTY(EditAnywhere, Category = "LowPower", meta = (DisplayName = "LowPowerIntensity"))
	float M_LowPowerIntensity = 2000;
	UPROPERTY(EditAnywhere, Category = "LowPower", meta = (DisplayName = "LowPowerRadius"))
	float M_LowPowerRadius = 300;

	bool M_bLowPowerMode;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void FlashlightSwitch();

	void Punishment();

};
