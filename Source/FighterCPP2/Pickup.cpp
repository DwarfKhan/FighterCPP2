// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
//NOTE: Can include but throws a bunch of errors when Calling Spawn(AFighter *fighter)
//#include "FighterCPP2/Fighter.h"
#include "Spawner.generated.h"

UCLASS()
class FIGHTERCPP2_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void Spawn(AActor *fighter) {
		FVector spawnPos = GetActorLocation();

		fighter->SetActorLocation(spawnPos);
	}
	
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    