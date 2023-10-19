/* eslint-disable react/jsx-one-expression-per-line */
/* eslint-disable max-len */
/* eslint-disable react/no-unescaped-entities */
import React, { useRef } from 'react';
import Section from './components/Section/Section';
import styles from './App.module.scss';
import FlyoutDiv from './components/FlyoutDiv/FlyoutDiv';
import ProfessionalExperienceCard from './components/Cards/ProfessionalExperienceCard/ProfessionalExperienceCard';

const App = () => {
  const section1 = useRef();
  const section2 = useRef();
  const section3 = useRef();

  return (
    <div className={`container ${styles.container}`}>
      <div ref={section1}>
        <Section headline="hi there, I'm Caleb" goToSectionRef={section2} theme="light">
          <FlyoutDiv>
            <div>React</div>
            <div>dab2</div>
            <div>dab3</div>
            <div>dab4</div>
            <div>dab5</div>
            <div>dab6</div>
            <div>dab7</div>
            <ProfessionalExperienceCard />
          </FlyoutDiv>
        </Section>
      </div>
      {/* <div ref={section2}>
        <Section headline="what do i do" goToSectionRef={section3} showArrow theme="dark"><div>dab</div></Section>
      </div>
      <div ref={section3}>
        <Section headline="section3" image="/android-studio.png" />
      </div> */}
    </div>
  );
};

export default App;
