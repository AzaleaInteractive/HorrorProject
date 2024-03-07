// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/HideActorBase.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AHideActorBase::AHideActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	M_RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = M_RootComp;

	M_MainMesh = CreateDefaultSubobject<UStaticMeshComponent>("MainMesh");
	M_MainMesh->SetupAttachment(RootComponent);

	M_SecondaryMesh = CreateDefaultSubobject<UStaticMeshComponent>("SecondaryMesh");
	M_SecondaryMesh->SetupAttachment(RootComponent);

	//M_Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	//M_Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHideActorBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}




// Called every frame
void AHideActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

