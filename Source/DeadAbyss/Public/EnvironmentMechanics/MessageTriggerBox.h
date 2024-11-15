// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Engine/DataTable.h"
#include "MessageTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class DEADABYSS_API AMessageTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	AMessageTriggerBox();
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void ChooseMessage();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,meta = (DisplayName = "MessageDataTable"))
	UDataTable* M_MessageDT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,meta = (DisplayName = "EnemyClass"))
	TSubclassOf<ACharacter> M_Enemy;
};
