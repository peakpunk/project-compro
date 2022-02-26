
// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryMan_GameMode.h"
#include "GameFramework/Actor.h"




ABatteryMan_GameMode::ABatteryMan_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryMan_GameMode::BeginPlay() {

	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ABatteryMan_GameMode::SpawnPlayerRecharge,
		FMath::RandRange(5, 10), true); //ปรับเวลาเกิด
}

void ABatteryMan_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryMan_GameMode::SpawnPlayerRecharge()
{

	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	//FVector SpawnPosition = FVector(10.0f, 10.0f, 500.0f);//ปรับตำแหน่ง
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	//GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}

void ABatteryMan_GameMode::SpawnJunpHigh()
{
	//FVector SpawnPosition = FVector(20.0f, 20.0f, 500.0f);//ปรับตำแหน่ง
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	//GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}
