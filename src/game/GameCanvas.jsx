import React, { useEffect } from 'react';
import useScript from '../useScript';

const GameCanvas = () => {
  useScript('./game.js');

  useEffect(() => {
    const script = document.createElement('script');
    script.innerHTML = `var Module = {
	  	canvas: (function() { return document.getElementById('canvas'); })()
  	};`;

    document.body.appendChild(script);

    return () => {
      document.body.removeChild(script);
    };
  }, []);

  return (
    <>
      <canvas id="canvas" />
    </>
  );
};

export default GameCanvas;
