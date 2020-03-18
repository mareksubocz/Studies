import sc2
from sc2 import run_game, maps, Race, Difficulty
from sc2.player import Bot, Computer

class WorkerRushBot(sc2.BotAI):
	async def on_step(self, iteration):
		if iteration == 0:
			for worker in self.workers:
				await self.do(worker.attack(self.enemy_start_locations[0]))

a = Bot(Race.Zerg, WorkerRushBot())
run_game(maps.get("AbyssalReefLE"), [
a,
Computer(Race.Protoss, Difficulty.Medium)
], realtime=True)