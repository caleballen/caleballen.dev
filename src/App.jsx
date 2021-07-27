/* eslint-disable react/jsx-one-expression-per-line */
/* eslint-disable max-len */
/* eslint-disable react/no-unescaped-entities */
import './App.css';
import React from 'react';
import Header from './Header';
import Card from './Card';

const App = () => (
  <div className="app">
    <Header />
    <Card>
      <img src="keyboard.png" alt="Java network system code" />
      <div>
        <h3>
          Full stack experience
        </h3>
        <p>I have a year's industry experience working with ReactJS, NodeJS, GraphQL and Docker</p>
      </div>

    </Card>
    <Card>
      <div>
        <h3>
          Networking and game-dev
        </h3>
        <p>In my free time I enjoy working on a 2D multiplayer Android game built in <b>Java</b> using <b>Netty</b>, <b>libgdx</b> and using <b>box2d</b> physics</p>
      </div>
      <img src="java-server-code.png" alt="Java network system code" />
    </Card>
    <Card>
      <img src="keras-cnn-model.png" alt="AI" />
      <div>
        <h3>
          Machine learning
        </h3>
        <p>In my studies at Queen's I've completed several <b>artificial intelligence</b> and <b>machine learning</b> based modules, learning how to use machine learning to detect faces in images, detect trends in medical scan data and recognise sentiment in online reviews.</p>
      </div>
    </Card>
    <Card>
      <img src="dscc-stream.png" alt="Disjoint Set Connected Components Concurrent Programming" />
      <div>
        <h3>
          Concurrent Programming
        </h3>
        <p>I enjoyed working with <b>concurrency</b> and completing an assignment which required competing against other students to produce the most <b>efficient</b> solution to a graph based problem</p>
        <p>Pictured is the core of my final code to compute the connected components of an undirected graph via a stream technique which did not require reading the entire graph to memory at once</p>
      </div>
    </Card>
    <Card>
      <img src="android-studio.png" alt="Disjoint Set Connected Components Concurrent Programming" />
      <div>
        <h3>
          Android Studio
        </h3>
        <p>talk about android stuff</p>
      </div>
      <img src="minimalist-launcher.png" alt="Disjoint Set Connected Components Concurrent Programming" />
    </Card>
    <Card>
      <div>
        <h3>
          linux
        </h3>
        <p>talk about android stuff</p>
      </div>
      <img src="linux.png" alt="Disjoint Set Connected Components Concurrent Programming" />
    </Card>
  </div>
);

export default App;
