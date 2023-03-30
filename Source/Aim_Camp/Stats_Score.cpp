// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats_Score.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/HUD.h"
#include "Engine/World.h
// Sets default values
AStats_Score::AStats_Score()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    // Set default values for score properties
    Precision = 0.0f;
    Hits = 0;
    Miss = 0;
    CurrentScore = 0;
    MaxScore = 0;
}

// Called when the game starts or when spawned
void AStats_Score::BeginPlay()
{
    Super::BeginPlay();
    
    // Get a reference to the stats blueprint
    Stats_ScoreWidget = Cast<UUserWidget>(GetWorld()->GetFirstPlayerController()->GetHUD()->GetWidgetFromName(TEXT("Stats_Score")));
}

// Called every frame
void AStats_Score::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AStats_Score::UpdatePrecision(bool Hit)
{
    // Calculate precision score based on Hits divided by Max Score
    if (Hit)
    {
        Hits++;
    }
    Precision = MaxScore > 0 ? (float)Hits / (float)MaxScore : 0.0f;
}

void AStats_Score::UpdateHits(int32 CurrentScore)
{
    // Increment the number of hits
    Hits += CurrentScore;
}

void AStats_Score::UpdateMiss(int32 CurrentScore, int32 MaxScore)
{
    // Calculate missed score based on Max Score subtracted by Current Score
    Miss = MaxScore - CurrentScore;
}

// Called to bind functionality to input
void AStats_Score::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Updates the stats blueprint
void AStats_Score::UpdateStats_ScoreBlueprint()
{
    if (Stats_ScoreWidget)
    {
        // Update the score values in the stats blueprint
        UTextBlock* PrecisionText = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("getPrecision")));
        if (PrecisionText)
        {
            PrecisionText->SetText(FText::AsNumber(Precision));
        }
        
        UTextBlock* HitsText = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("getHits")));
        if (HitsText)
        {
            HitsText->SetText(FText::AsNumber(Hits));
        }
        
        UTextBlock* MissText = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("getMiss")));
        if (MissText)
        {
            MissText->SetText(FText::AsNumber(Miss));
        }
    }
}
