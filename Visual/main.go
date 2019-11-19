package main

import r "github.com/lachee/raylib-goplus/raylib"

var camera r.Camera

func inita() {
	r.InitWindow(800, 400, "Raylib Go Plus")
	r.SetMouseScale(1, 1)
	camera = r.NewCamera(r.NewVector3(0.0, 10.0, 10.0), r.NewVector3(0.0, 0.0, 0.0),
		r.NewVector3(0.0, 1.0, 0.0), 45, r.CameraTypePerspective)

	r.SetCameraMode(&camera, r.CameraFirstPerson)
	r.SetTargetFPS(60)

}

func drawBoard() {

	r.BeginMode3D(camera)
	r.UpdateCamera(&camera)
	r.DrawSphere(r.NewVector3(-.5, 0.5, -.5), .5, r.Red)
	r.DrawGrid(20, 1.0)

	r.EndMode3D()
}

func drawUI() {

}

func main() {
	inita()
	// val := float32(50)
	// b := true
	// tmp := r.NewRectangle(600, 40, 120, 20)
	for !r.WindowShouldClose() {
		r.BeginDrawing()
		r.ClearBackground(r.RayWhite)

		drawBoard()

		r.DrawFPS(10, 10)
		r.EndDrawing()
	}
	r.CloseWindow()
}

// val = r.GuiSliderBar(tmp, "left", "right", val, 0, 720)
// 		b = r.GuiCheckBox(r.Rectangle{X: 100, Y: 60, Width: 20, Height: 20}, "box", b)

// 		if r.GuiButton(r.Rectangle{X: 100, Y: 30, Width: 200, Height: 20}, "Toggle Window") {
// 			b = !b
// 		}
// 		Pos := r.GetMousePosition()

// 		r.DrawCircle(int(Pos.X), int(Pos.Y), 3, r.Red)
