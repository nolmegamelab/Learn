# Roblox Architecture 

https://tandemcoder.com/understanding-roblox-architecture-how-roblox-games-work/

## Client side scripts

LocalScript라고 부른다. LocalScript는 다음의 하위 클래스여야 한다. 

- A Chracter Model 
- Player GUI 
- Backpack 
- PlayerScripts 
- Tool 
- ReplicatedFirst 

## Server side scripts

서버 스크립트는 Script 타잎으로 다음의 하위 클래스이다. 

- Workspace
- ServerScriptService
- Backpack 

## Replciation 

언리얼처럼 복제를 사용한다. 입력 이벤트, 물리, 애님 트랙 등이 복제 대상이다. 

## Validation 

RemoteEvent를 사용하여 전달하고 서버에서 스크립트를 실행하여 결과를 처리한다. 

## Network Ownership 

물리를 시뮬레이션하는 부품의 경우 누가 소유권을 갖고 시뮬레이하는 지를 알아야 한다. 가장 가까운 플레이어 또는 서버가 소유권을 갖는다. 

## Event based design 

Debouncing 

## Bindable events 

## What is a Service? 

- TeleportService 
- AssertService 
- GuiService 
- GamePassService 
- MarketplaceService
- SoundService
- GroupService
- CollectionService

## Storage와 lua 

lua에 많이 의존하는 구조이다. 전체 서버가 어떻게 구현되었는지는 문서만으로 알기 어렵다. Event와 Instance가 전체 구조의 핵심이다. 이에 기반하여 전체가 동작한다. 



