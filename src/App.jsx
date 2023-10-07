/* eslint-disable react/jsx-one-expression-per-line */
/* eslint-disable max-len */
/* eslint-disable react/no-unescaped-entities */
import React, { useRef } from 'react';
import Section from './components/Section/Section';
import styles from './App.module.scss';

const App = () => {
  const section1 = useRef();
  const section2 = useRef();
  const section3 = useRef();

  return (
    <div className={`container ${styles.container}`}>
      <div ref={section1}>
        <Section headline="hey, I'm Caleb" goToSectionRef={section2} showArrow theme="light" />
      </div>
      <div ref={section2}>
        <Section headline="section2" image="/linux.png" goToSectionRef={section3} showArrow />
      </div>
      <div ref={section3}>
        <Section headline="section3" image="/android-studio.png" />
      </div>
    </div>
  );
};

export default App;
