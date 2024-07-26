// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine


#include "CoreCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"

ACoreCharacter::ACoreCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;
	CameraArm_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	Camera_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Weapon_ = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));

	Camera_->SetupAttachment(CameraArm_);
	CameraArm_->SetupAttachment(RootComponent);
    Weapon_->SetupAttachment(GetMesh());
}

void ACoreCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoreCharacter::OnRotationInput(const FInputActionInstance& Instance)
{
    const float RotationValue{Instance.GetValue().Get<float>()};
    FRotator CurrentRotation{GetActorRotation()};
    CurrentRotation.Yaw += RotationValue;
    SetActorRotation(CurrentRotation);
}

void ACoreCharacter::OnMoveForwardInput(const FInputActionInstance& Instance)
{
    AddMovementInput(GetActorForwardVector(), Instance.GetValue().Get<float>());
}

void ACoreCharacter::OnMoveRightInput(const FInputActionInstance& Instance)
{
    AddMovementInput(GetActorRightVector(), Instance.GetValue().Get<float>());
}

void ACoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    {
        ULocalPlayer* Player{GetWorld()->GetFirstLocalPlayerFromController()};
        check(Player);
        UEnhancedInputLocalPlayerSubsystem* EnhancedInputSystem{Player->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()};
        check(EnhancedInputSystem);
        check(!InputMapping_.IsNull());
        EnhancedInputSystem->AddMappingContext(InputMapping_.LoadSynchronous(), 0);
    }

    UEnhancedInputComponent* EnhancedInput{Cast<UEnhancedInputComponent>(PlayerInputComponent)};
    check(EnhancedInput);

    {
        check(InputActions_.Rotation);
        EnhancedInput->BindAction(InputActions_.Rotation,
            ETriggerEvent::Triggered, this, &ThisClass::OnRotationInput);
    }

    {
        check(InputActions_.MoveForward);
        EnhancedInput->BindAction(InputActions_.MoveForward,
            ETriggerEvent::Triggered, this, &ThisClass::OnMoveForwardInput);
    }

    {
        check(InputActions_.MoveRight);
        EnhancedInput->BindAction(InputActions_.MoveRight,
            ETriggerEvent::Triggered, this, &ThisClass::OnMoveRightInput);
    }
}
