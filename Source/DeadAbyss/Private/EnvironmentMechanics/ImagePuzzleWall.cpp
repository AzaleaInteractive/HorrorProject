// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/ImagePuzzleWall.h"

// Sets default values
AImagePuzzleWall::AImagePuzzleWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	M_RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = M_RootComp;
	
}

// Called when the game starts or when spawned
void AImagePuzzleWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AImagePuzzleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

