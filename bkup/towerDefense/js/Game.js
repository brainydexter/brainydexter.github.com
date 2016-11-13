// Game code begins
var Game = function()
{
	console.log('Game instance created');
}

var vShader='\
void main() \
{ \
	gl_Position = projectionMatrix * modelViewMatrix * vec4(position,1.0); \
} \
';
var fShader = '\
void main() \
{ \
	gl_FragColor 	= vec4(1.0,0.0,0.8,1.0); \
} \
';

Game.prototype.init = function(){
	this.keyboard = new KeyboardState();

	var WIDTH = 800;
	var HEIGHT = 600;

	this.scene = new THREE.Scene();

	this.camera = new THREE.OrthographicCamera( 0, WIDTH, 0, HEIGHT, -10, 1000 );
	this.camera.position.set(0, 0, 100);
	this.camera.lookAt(new THREE.Vector3( 0, 0, 0 ));
	this.scene.add(this.camera);

	this.renderer = new THREE.WebGLRenderer();
	this.renderer.setSize( WIDTH, HEIGHT );
	document.body.appendChild( this.renderer.domElement );

	var NxN = 5;
	var geometry = new THREE.BoxGeometry( Constants.BLOCK_WIDTH, Constants.BLOCK_WIDTH, 4 );
	// var material = new THREE.MeshBasicMaterial( { color: 0x00ff00 } );
	var shaderMaterial = new THREE.ShaderMaterial( {
		vertexShader: vShader,
		fragmentShader: fShader
	} );
	
	var cube2 = new THREE.Mesh( geometry, shaderMaterial);
	cube2.position.set(650, 300, 0);
	this.scene.add(cube2);

	// this.cube = new THREE.Mesh( geometry, material );
	// this.cube.position.set(WIDTH/2, HEIGHT/2, 1);
	// this.scene.add( this.cube );
	
	// when the mouse moves, call the given function
	// document.addEventListener( 'click', onDocumentMouseDown, false );
	
	this.clock = new THREE.Clock( true );
};

function onDocumentMouseDown( event ) {
}

Game.prototype.update = function(dt){
	// console.log('Time elapsed: ' + dt);
	this.keyboard.update();

};

Game.prototype.render = function(){
	var thisObj = this;
	requestAnimationFrame( function() {thisObj.render();} );

	// rendering code goes here
	var delta = this.clock.getDelta();

	this.renderer.render(this.scene, this.camera);
	
};

Game.prototype.destroy = function() {
	this.keyboard.destroy();
};
// Game code ends