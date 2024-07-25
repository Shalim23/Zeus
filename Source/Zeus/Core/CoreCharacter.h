// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CoreCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;

UCLASS()
class ZEUS_API ACoreCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACoreCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> Camera_;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> CameraArm_;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TSoftObjectPtr<UInputMappingContext> InputMapping;
};
