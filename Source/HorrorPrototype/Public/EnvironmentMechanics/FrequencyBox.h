// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "FrequencyBox.generated.h"

UCLASS()
class HORRORPROTOTYPE_API AFrequencyBox : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "BaseMesh"))
	UStaticMeshComponent* M_BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "DoorMesh"))
	UStaticMeshComponent* M_DoorMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "InteractBox"))
	UBoxComponent* M_InteractBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", DisplayName = "CameraComp"))
	UCameraComponent* M_CameraComp;
	
public:	
	// Sets default values for this actor's properties
	AFrequencyBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OpenBox();

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedActor, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta = (DisplayName = "CanInteract"))
	bool M_bCanInteract;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta = (DisplayName = "SingleItem", ExposeOnSpawn = "true"))
	bool M_bSingleItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "CorrectFrequency"))
	int M_CorrectFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "CurrentFrequency"))
	float M_CurrentFrequency = 90;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> M_PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta = (DisplayName = "TargetObject", ExposeOnSpawn = "true"))
	AActor* M_TargetObject;

	

};
