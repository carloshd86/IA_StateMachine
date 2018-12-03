function createImage(texture_name, char_size)
	local gfxQuad = MOAIGfxQuad2D.new()
	gfxQuad:setTexture(texture_name)
	char_size = 64
	gfxQuad:setRect(-char_size/2, -char_size/2, char_size/2, char_size/2)
	gfxQuad:setUVRect(0, 0, 1, 1)
	return gfxQuad
end

MOAISim.openWindow("game", 1024, 768)

viewport = MOAIViewport.new()
viewport:setSize (1024, 768)
viewport:setScale (1024, -768)

layer = MOAILayer2D.new()
layer:setViewport(viewport)
MOAISim.pushRenderPass(layer)

char_size = 64
gfxQuad = createImage("dragon.png", char_size)
gfxQuad1 = createImage("dragon_dead.png", char_size)
gfxQuad2 = createImage("dragon_attack.png", char_size)
gfxQuad3 = createImage("dragon_idle.png", char_size)
gfxQuad4 = createImage("dragon_alarm.png", char_size)
gfxQuad5 = createImage("dragon_hit.png", char_size)

-- Enemy
prop = MOAIProp2D.new()
prop:setDeck(gfxQuad)

enemy = Enemy.new()
-- Add prop to be the renderable for this enemy
enemy:setProp(prop, layer)
-- Start the enemy (allow calls to OnUpdate)
enemy:start()
enemy:setLoc(0, 0)
enemy:setRot(0)
enemy:setLinearVel(0, 0)
enemy:setAngularVel(0)

-- Character
prop = MOAIProp2D.new()
prop:setDeck(gfxQuad)

entity = Character.new()
-- Add prop to be the renderable for this character
entity:addImage(gfxQuad)    -- SetImage(0)  dragon.png
entity:addImage(gfxQuad3)   -- SetImage(1)  dragon_idle.png
entity:addImage(gfxQuad4)   -- SetImage(2)  dragon_alarm.png
entity:addImage(gfxQuad2)   -- SetImage(3)  dragon_attack.png

entity:setProp(prop, layer)

-- Start the character (allow calls to OnUpdate)
entity:start()
entity:setLoc(-200, -200)
entity:setRot(0)
entity:setLinearVel(20, 20)
entity:setAngularVel(30)
entity:setEnemy(enemy)


-- Enable Debug Draw
debug = MOAIDrawDebug.get();
layer:setDrawDebug(debug)
-- Add this character to draw debug
MOAIDrawDebug.insertEntity(entity)
MOAIDrawDebug.insertEntity(enemy)

mouseX = 0
mouseY = 0

function onClick(down)
  -- entity:setLoc(mouseX, mouseY)
  -- entity:setRot(-135)
end

function pointerCallback(x, y)
    mouseX, mouseY = layer:wndToWorld(x, y)
end

MOAIInputMgr.device.mouseLeft:setCallback(onClick)
MOAIInputMgr.device.pointer:setCallback(pointerCallback)