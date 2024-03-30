// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/RechargeStation.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARechargeStation::ARechargeStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	M_RootComp = CreateDefaultSubobject<USceneComponent>("RooComp");
	RootComponent = M_RootComp;

	M_RechargeMesh = CreateDefaultSubobject<UStaticMeshComponent>("RechargeMesh");
	M_RechargeMesh->SetupAttachment(M_RootComp);

	M_CharacterLocationArrow = CreateDefaultSubobject<UArrowComponent>("CharacterTeleportLocation");
	M_CharacterLocationArrow->SetupAttachment(M_RootComp);

	M_InteractBox = CreateDefaultSubobject<UBoxComponent>("InteractBox");
	M_InteractBox->SetupAttachment(M_RootComp);

}

// Called when the game starts or when spawned
void ARechargeStation::BeginPlay()
{
	Super::BeginPlay();

	M_PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	M_InteractBox->OnComponentBeginOverlap.AddDynamic(this, &ARechargeStation::OnBoxOverlap);
	M_InteractBox->OnComponentEndOverlap.AddDynamic(this, &ARechargeStation::OnBoxEndOverlap);
	
}

void ARechargeStation::Recharge(ACharacter* CharacterPawn)
{
	
	if (CharacterPawn)
	{
		M_CharacterPawn = CharacterPawn;
		float AnimationTime = 2;
		CharacterPawn->DisableInput(M_PC);
		if (M_RechargeAnimation)
		{
			AnimationTime = CharacterPawn->PlayAnimMontage(M_RechargeAnimation);
		}
		FTimerHandle AnimationTimerHandle;
		GetWorldTimerManager().SetTimer(AnimationTimerHandle, this, &ARechargeStation::EndCharging, AnimationTime, false);
		
	}
}


void ARechargeStation::EndCharging()
{
	if (M_CharacterPawn)
	{
		M_CharacterPawn->EnableInput(M_PC);
		M_RechargeFlashlight.Broadcast();
	}
}

void ARechargeStation::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		M_CanInteract = true;
	}
}

void ARechargeStation::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		M_CanInteract = false;
	}
}

// Called every frame
void ARechargeStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

