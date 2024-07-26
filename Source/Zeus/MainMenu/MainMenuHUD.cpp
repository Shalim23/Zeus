// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine


#include "MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/AssetManager.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    check(!MainMenuWidgetClass_.IsNull());

    FStreamableManager& StreamableManager{UAssetManager::GetStreamableManager()};
    
    StreamableManager.RequestAsyncLoad(MainMenuWidgetClass_.ToSoftObjectPath(), 
        [this]
        {
            UClass* LoadedClass{ MainMenuWidgetClass_.Get() };
            check(LoadedClass)
            MainMenuWidget_ = CreateWidget(GetOwner<APlayerController>(), LoadedClass);
            check(MainMenuWidget_);
            MainMenuWidget_->AddToViewport();
        });
}
