/* eslint-disable max-len */
/* eslint-disable react/no-unescaped-entities */
import './App.css';
import React from 'react';
import ParallaxImage from './ParallaxImage';
import Header from './Header';

const App = () => (
  <div className="app">
    <Header />
    <ParallaxImage
      caption="java"
      below="I wrote some netty code"
      image="java-server-code.png"
    />
    <ParallaxImage id="dab" below="dab" image="coffee.jpg" />
  </div>
);

export default App;
