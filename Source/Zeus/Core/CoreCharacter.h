// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CoreCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionInstance;

USTRUCT(BlueprintType)
struct FCoreCharacterInputActions
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> Rotation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> MoveForward;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> MoveRight;
};

UCLASS()
class ZEUS_API ACoreCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACoreCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	void OnRotationInput(const FInputActionInstance& Instance);
	void OnMoveForwardInput(const FInputActionInstance& Instance);
	void OnMoveRightInput(const FInputActionInstance& Instance);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TObjectPtr<USkeletalMeshComponent> Weapon_;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> Camera_;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> CameraArm_;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TSoftObjectPtr<UInputMappingContext> InputMapping_;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	FCoreCharacterInputActions InputActions_;
};
