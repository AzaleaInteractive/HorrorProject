// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentMechanics/MessageTriggerBox.h"

#include "Components/ShapeComponent.h"
#include "GameFramework/Character.h"

AMessageTriggerBox::AMessageTriggerBox()
{

}

void AMessageTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMessageTriggerBox::OnBeginOverlap);
}

void AMessageTriggerBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass() == M_Enemy)
	{
		ChooseMessage();
	}
}
