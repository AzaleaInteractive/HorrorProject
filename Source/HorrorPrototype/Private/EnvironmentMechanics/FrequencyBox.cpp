// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/FrequencyBox.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFrequencyBox::AFrequencyBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	M_RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = M_RootComp;

	M_BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	M_BaseMesh->SetupAttachment(RootComponent);

	M_DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	M_DoorMesh->SetupAttachment(RootComponent);

	M_InteractBox = CreateDefaultSubobject<UBoxComponent>("InteractBox");
	M_InteractBox->SetupAttachment(RootComponent);

	M_CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	M_CameraComp->SetupAttachment(RootComponent);

	
	

}

// Called when the game starts or when spawned
void AFrequencyBox::BeginPlay()
{
	Super::BeginPlay();

	M_InteractBox->OnComponentBeginOverlap.AddDynamic(this, &AFrequencyBox::OnBoxOverlap);
	M_InteractBox->OnComponentEndOverlap.AddDynamic(this, &AFrequencyBox::OnBoxEndOverlap);

	M_CorrectFrequency = UKismetMathLibrary::RandomIntegerInRange(0, 360);
}

void AFrequencyBox::OnBoxOverlap(UPrimitiveComponent* OverlappedActor, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass() == M_PlayerCharacter)
	{
		M_bCanInteract = true;
	}
}

void AFrequencyBox::OnBoxEndOverlap(UPrimitiveComponent* OverlappedActor, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->GetClass() == M_PlayerCharacter)
	{
		M_bCanInteract = false;
	}
}

// Called every frame
void AFrequencyBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

