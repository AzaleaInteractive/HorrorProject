// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SimonSaysPuzzle.generated.h"

UENUM (BlueprintType)
enum class ELevel : uint8
{
	E_Level1 UMETA(DisplayName = "Level1"),
	E_Level2 UMETA(DisplayName = "Level2"),
	E_Level3 UMETA(DisplayName = "Level3"),
	E_Level4 UMETA(DisplayName = "Level4"),
};

UCLASS()

class HORRORPROTOTYPE_API ASimonSaysPuzzle : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "MainMesh"))
	UStaticMeshComponent* M_MainMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "Camera"))
	UCameraComponent* M_Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "InteractBox"))
	UBoxComponent* M_InteractBox;
	
public:	
	// Sets default values for this actor's properties
	ASimonSaysPuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<int> M_OrderArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "LevelEnum"))
	ELevel M_LevelEnum = ELevel::E_Level1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "CorrectPassword"))
	FString M_CorrectPassword;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "PlayerInputPassword"))
	FString M_PlayerInputPassword;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (DisplayName = "CanInteract"))
	bool M_bCanInteract;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default",meta = (ExposeOnSpawn = "true", DisplayName = "TargetActor"))
	AActor* M_TargetActor;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
