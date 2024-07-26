// Copyright@ Shalimov Dmytro 23.04.1991 Kyiv Ukraine


#include "ZeusBlueprintFunctionLibrary.h"

void UZeusBlueprintFunctionLibrary::BlueprintAssertMessage(const bool Value, const FString& Message)
{
    checkf(Value, TEXT("%s"), *Message);
}
