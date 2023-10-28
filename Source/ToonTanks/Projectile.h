// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Mesh")
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category="Particle")
	class UParticleSystemComponent* FollowingComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalInpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float BaseDamage = 50.f;

	UPROPERTY(EditAnywhere, Category="Particle")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "Sound")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
