// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/SimonSaysPuzzle.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"

// Sets default values
ASimonSaysPuzzle::ASimonSaysPuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	M_RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = M_RootComp;

	M_MainMesh = CreateDefaultSubobject<UStaticMeshComponent>("MainMesh");
	M_MainMesh->SetupAttachment(RootComponent);

	M_Camera = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	M_Camera->SetupAttachment(RootComponent);

	M_InteractBox = CreateDefaultSubobject<UBoxComponent>("InteractBox");
	M_InteractBox->SetupAttachment(RootComponent);

	M_OrderArray.Add(1);
	M_OrderArray.Add(2);
	M_OrderArray.Add(3);
	M_OrderArray.Add(4);

}

// Called when the game starts or when spawned
void ASimonSaysPuzzle::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ASimonSaysPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


