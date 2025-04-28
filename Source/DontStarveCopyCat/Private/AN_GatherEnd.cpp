// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_GatherEnd.h"
#include "DS_Player.h"

void UAN_GatherEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp)
	{
		ADS_Player* PlayerCharacter = Cast<ADS_Player>(MeshComp->GetOwner());
		if (PlayerCharacter)
		{
			PlayerCharacter->GatehrEndNotify();
		}
	}
}
