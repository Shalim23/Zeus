// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"


UCLASS()
class ZEUS_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> MainMenuWidgetClass_;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UUserWidget> MainMenuWidget_;
};
