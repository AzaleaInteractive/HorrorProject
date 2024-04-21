// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"

// Sets default values
AFlashlight::AFlashlight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	M_RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = M_RootComponent;

	M_FlashlightMesh = CreateDefaultSubobject<UStaticMeshComponent>("FlashlightMesh");
	M_FlashlightMesh->SetupAttachment(RootComponent);

	M_Spotlight = CreateDefaultSubobject<USpotLightComponent>("Spotlight");
	M_Spotlight->SetupAttachment(M_FlashlightMesh);
	M_Spotlight->SetHiddenInGame(true);

	M_CurrentBattery = M_MaxBattery;

}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlashlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::SanitizeFloat(M_Delay));


	if (M_bFlashlightOn && M_CurrentBattery > 0)
	{
		M_bLowPowerMode = false;
		M_Spotlight->SetAttenuationRadius(1000);
		M_Spotlight->SetIntensity(6000);
		M_CurrentBattery -= M_DecayRate;
		M_Delay = 10;
		M_CurrentBattery = FMath::Clamp(M_CurrentBattery, 0, M_MaxBattery);

		if (M_CurrentBattery == 0 && !M_bLowPowerMode)
		{
			M_bLowPowerMode = true;
			M_Spotlight->SetAttenuationRadius(M_LowPowerRadius);
			M_Spotlight->SetIntensity(M_LowPowerIntensity);
		}

	}
	

}

void AFlashlight::FlashlightSwitch()
{
	if (M_bFlashlightOn)
	{
		// Turn On Flashlight
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("FlashlightOn"));
		M_Spotlight->SetHiddenInGame(false);
	}
	else if (!M_bFlashlightOn)
	{
		// Turn Off Flashlight
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("FlashlightOff"));
		M_Spotlight->SetHiddenInGame(true);
	}
}


