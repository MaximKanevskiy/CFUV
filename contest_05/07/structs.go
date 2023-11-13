type Water struct {
	temperature int
	boiling     bool
}

func NewWater(temperature int) *Water {
	return &Water{
		temperature: temperature,
		boiling:     false,
	}
}

func (w *Water) is_boiling() bool {
	if w.temperature >= 100 {
		return true
	} else {
		return false
	}
}

type Teapot struct {
	water *Water
}

func NewTeapot(water *Water) *Teapot {
	return &Teapot{
		water: water,
	}
}

func (t *Teapot) heat_up(heat int) int {
	t.water.temperature += heat
	return t.water.temperature
}

func (t *Teapot) is_boiling() bool {
	if t.water.is_boiling() {
		t.water.boiling = true
		return t.water.boiling
	} else {
		t.water.boiling = false
		return t.water.boiling
	}
}
