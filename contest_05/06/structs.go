type Box struct {
	isOpened bool
}

type Cat struct {
	isAlive bool
}

// Определяем метод is_alive() для структуры Cat
func (c Cat) is_alive() bool {
	return c.isAlive
}

// Определяем метод open() для структуры Box
// Метод возвращает экземпляр стурктуры Cat
func (b Box) open() *Cat {
  // Проверка на открытую коробку для того, чтобы избежать изменения статуса кота после открытия
	if !b.isOpened {
		b.isOpened = true

		rand.Seed(time.Now().UnixNano()) // Инициализируем генератор случайных чисел с текущим временем

		if rand.Intn(2) == 0 {
			return &Cat{isAlive: true}
		} else {
			return &Cat{isAlive: false}
		}
	}

	return nil
}
