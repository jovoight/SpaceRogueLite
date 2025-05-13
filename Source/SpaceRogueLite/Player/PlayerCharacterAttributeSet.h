#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "PlayerCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SPACEROGUELITE_API UPlayerCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPlayerCharacterAttributeSet();

	/** Health **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UPlayerCharacterAttributeSet, Health);

	/** Armor **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UPlayerCharacterAttributeSet, Armor);

	/** Shield **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UPlayerCharacterAttributeSet, Shield)

	/** Replication boilerplate **/
	virtual void
	GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override
	{
		Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		DOREPLIFETIME_CONDITION_NOTIFY(UPlayerCharacterAttributeSet, Health, COND_None,
		                               REPNOTIFY_Always);
		DOREPLIFETIME_CONDITION_NOTIFY(UPlayerCharacterAttributeSet, Armor, COND_None,
		                               REPNOTIFY_Always);
		DOREPLIFETIME_CONDITION_NOTIFY(UPlayerCharacterAttributeSet, Shield, COND_None,
		                               REPNOTIFY_Always);
	}

	/** Called on attribute change **/
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
