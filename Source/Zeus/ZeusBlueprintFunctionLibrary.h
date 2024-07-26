// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZeusBlueprintFunctionLibrary.generated.h"

UCLASS()
class ZEUS_API UZeusBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static void BlueprintAssertMessage(const bool Value, const FString& Message);
};
