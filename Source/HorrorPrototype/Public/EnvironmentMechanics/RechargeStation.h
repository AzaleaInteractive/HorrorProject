// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RechargeStation.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRechargeFlashlight);

UCLASS()
class HORRORPROTOTYPE_API ARechargeStation : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RootComp"))
	USceneComponent* M_RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "RechargeMesh"))
	UStaticMeshComponent* M_RechargeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "CharacterTeleportLocation"))
	UArrowComponent* M_CharacterLocationArrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", DisplayName = "InteractBox"))
	UBoxComponent* M_InteractBox;

	
	
public:	
	// Sets default values for this actor's properties
	ARechargeStation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	APlayerController* M_PC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "CharacterPawn"))
	ACharacter* M_CharacterPawn;

	UFUNCTION(BlueprintCallable)
	void Recharge(ACharacter* CharacterPawn);
	

	void EndCharging();

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "RechargeDelegate"))
	FRechargeFlashlight M_RechargeFlashlight;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "RechargeAnimation"))
	UAnimMontage* M_RechargeAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "bCanInteract"))
	bool M_CanInteract;


	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
