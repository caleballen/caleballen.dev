/* eslint-disable max-len */
/* eslint-disable react/no-unescaped-entities */
import './App.css';
import React from 'react';
import Card from './Card';
import Header from './Header';

const App = () => (
  <div className="app">
    <Header />
    <Card
      text="there's nothing here"
      image="java-server-code.png"
    />
    <Card id="dab" text="dab" image="java-server-code.png" />
  </div>
);

export default App;
