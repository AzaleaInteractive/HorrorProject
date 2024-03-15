// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FrequencyDoor.generated.h"

UCLASS()
class HORRORPROTOTYPE_API AFrequencyDoor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "DoorMesh"))
	UStaticMeshComponent* M_DoorMesh;
	
public:	
	// Sets default values for this actor's properties
	AFrequencyDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	void RotateDoor();

	UFUNCTION(BlueprintCallable)
	void OpenDoor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle M_RotateDoor;

	FRotator M_StartRotation;

};
