// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine


#include "CoreCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACoreCharacter::ACoreCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;
	CameraArm_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	Camera_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera_->SetupAttachment(CameraArm_);
	CameraArm_->SetupAttachment(RootComponent);
}

void ACoreCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
