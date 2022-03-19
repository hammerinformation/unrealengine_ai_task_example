#include "Task_Patrol.h"
#include "NavigationSystem.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NewAIController.h"
UTask_Patrol::UTask_Patrol(const FObjectInitializer& ObjectInitializer) {
	NodeName = TEXT("Patrol");
}
EBTNodeResult::Type UTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const AIController = Cast<ANewAIController>(OwnerComp.GetAIOwner());
	auto const Pawn = AIController->GetPawn();
	FNavLocation Loc;
	FVector const Origin = Pawn->GetActorLocation();
	UNavigationSystemV1* const NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavigationSystem->GetRandomReachablePointInRadius(Origin, 800.0f, Loc)) {
		AIController->GetBlackboardComponent()->SetValueAsVector("RandomLocation", Loc.Location);
		return EBTNodeResult::Succeeded;

	}
	else {
		return EBTNodeResult::Failed;

	}
	

	
}
