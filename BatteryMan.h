

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Blueprint/UserWidget.h"
#include "BatteryMan.generated.h"





UCLASS()
class MYPROJECT2_API ABatteryMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABatteryMan();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	bool bDead;
	
	
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	    float Power;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float HighScore;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Item;
		
	
	UPROPERTY(EditAnywhere)
		float Power_Treshold;
	UPROPERTY(EditAnywhere)
		float Item_Treshold;

	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* Hitcomp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> Player_Power_Widget_Class;
	UUserWidget* Player_Power_Widget;

	UPROPERTY(EditAnywhere, Category = "UI Score")
		TSubclassOf<UUserWidget> Player_Score_Widget_Class;
	UUserWidget* Player_Score_Widget;

	void RestartGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

//99++
