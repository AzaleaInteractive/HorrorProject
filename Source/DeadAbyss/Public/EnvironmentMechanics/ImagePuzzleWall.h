// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DecalComponent.h"
#include "ImagePuzzleWall.generated.h"

UCLASS()
class DEADABYSS_API AImagePuzzleWall : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;


	
	
public:	
	// Sets default values for this actor's properties
	AImagePuzzleWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
