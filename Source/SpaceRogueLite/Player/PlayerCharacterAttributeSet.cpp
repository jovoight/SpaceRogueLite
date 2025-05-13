// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UPlayerCharacterAttributeSet::UPlayerCharacterAttributeSet()
{
	/** Initialize Defaults **/
}

void UPlayerCharacterAttributeSet::PostGameplayEffectExecute(
	const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	/** Health clamping **/
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		Health.SetCurrentValue(FMath::Max(0.f, Health.GetCurrentValue()));
	}
}
