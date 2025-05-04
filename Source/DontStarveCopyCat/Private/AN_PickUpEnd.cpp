// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_PickUpEnd.h"
#include "DS_Player.h"

void UAN_PickUpEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (MeshComp)
	{
		ADS_Player* PlayerCharacter = Cast<ADS_Player>(MeshComp->GetOwner());
		if (PlayerCharacter)
		{
			PlayerCharacter->PickUpEndNotify();
		}
	}
}
