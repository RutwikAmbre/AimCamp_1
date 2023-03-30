// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Stats_Score.generated.h"

UCLASS()
class AIM_CAMP_API AStats_Score : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AStats_Score();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    float Precision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    int32 Hits;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    int32 Miss;

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdatePrecision(bool Hit);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateHits();

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateMiss();

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateStats_ScoreBlueprint();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    int32 CurrentScore;
    int32 MaxScore;

    UUserWidget* Stats_ScoreWidget;
};
