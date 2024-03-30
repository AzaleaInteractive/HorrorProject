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
		M_CurrentBattery -= M_DecayRate;
		M_Delay = 10;
		M_CurrentBattery = FMath::Clamp(M_CurrentBattery, 0, M_MaxBattery);

		if (M_CurrentBattery == 0)
		{
			FTimerHandle PunishmentHandle;
			M_bFlashlightOn = false;
			M_bPunishement = true;
			FlashlightSwitch();
			GetWorldTimerManager().SetTimer(PunishmentHandle, this, &AFlashlight::Punishment, 2);
		}

	}
	

}

void AFlashlight::FlashlightSwitch()
{
	if (!M_bFlashlightOn)
	{
		M_bFlashlightOn = false;
		M_Spotlight->SetHiddenInGame(true);
	}
	else if (M_bFlashlightOn)
	{
		M_bFlashlightOn = true;
		M_Spotlight->SetHiddenInGame(false);
	}
}

void AFlashlight::Punishment()
{
	M_bPunishement = false;
}

