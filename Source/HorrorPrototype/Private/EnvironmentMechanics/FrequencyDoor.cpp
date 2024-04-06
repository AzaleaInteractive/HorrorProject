// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/FrequencyDoor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFrequencyDoor::AFrequencyDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	M_RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = M_RootComp;

	M_DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	M_DoorMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorMesh(TEXT("/Game/Project/Art/Meshes/Environment/Door2"));
    if (DoorMesh.Object)
    {
	    M_DoorMesh->SetStaticMesh(DoorMesh.Object);
    }

}

// Called when the game starts or when spawned
void AFrequencyDoor::BeginPlay()
{
	Super::BeginPlay();

	M_StartRotation = M_DoorMesh->GetComponentRotation();
	
}

void AFrequencyDoor::RotateDoor()
{
	if (M_DoorMesh->GetComponentRotation() != M_StartRotation + FRotator(0,90,0))
	{
		const FRotator NewRot = UKismetMathLibrary::RInterpTo(GetActorRotation(), M_StartRotation + FRotator(0,90,0), UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 0.3);
		M_DoorMesh->SetRelativeRotation(NewRot);

		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Not Same Rotation"));
	}
	else
	{
		GetWorldTimerManager().ClearTimer(M_RotateDoor);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("ClearTimer"));
	}
}

void AFrequencyDoor::OpenDoor()
{
	GetWorldTimerManager().SetTimer(M_RotateDoor, this, &AFrequencyDoor::RotateDoor, 0.01, true);
}

// Called every frame
void AFrequencyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

