// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "PlayerCharacterAttributeSet.h"
#include "PlayerCharacter.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;

UCLASS(Blueprintable)
class SPACEROGUELITE_API APlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void Tick(float DeltaSeconds) override;

	/** Camera **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const
	{
		return TopDownCameraComponent;
	}

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** End Camera **/

protected:
	/** Movement **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveRightAction;

	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	/** End Movement **/

	/** Ability System **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UPlayerCharacterAttributeSet* Attributes;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	/** End Ability System **/

private:
	/** Camera **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	/** End Camera **/

	/** Default Attributes **/
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultAttributesEffect;
};
