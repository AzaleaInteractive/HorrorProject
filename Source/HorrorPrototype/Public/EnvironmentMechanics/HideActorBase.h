// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "HideActorBase.generated.h"

UENUM(BlueprintType)
enum class EHidingSpotType : uint8
{
	E_Locker UMETA(DisplayName="Locker"),
	E_Desk UMETA(DisplayName="Desk"),
	E_Bed UMETA(DisplayName="Bed"),
};

UCLASS()
class HORRORPROTOTYPE_API AHideActorBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHideActorBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "MainMesh"))
	UStaticMeshComponent* M_MainMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "SecondaryMesh"))
	UStaticMeshComponent* M_SecondaryMesh;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "HitBox"))
	UBoxComponent* M_HitBox;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hiding Enum",meta = (ExposeOnSpawn = "true", DisplayName = "HidingSpotEnum"))
	EHidingSpotType M_HidingSpot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "CanHide"))
	bool M_bCanHide;
	
};
